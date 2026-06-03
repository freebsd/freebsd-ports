from os import path
import sqlite3

__version__ = "0.1.9"
__version_info__ = tuple(__version__.split("."))


def loadable_path():
    """Returns the full path to the sqlite-vec loadable SQLite extension bundled with this package"""
    lp = path.join(path.dirname(__file__), "vec0")
    return path.normpath(lp)


def load(conn: sqlite3.Connection) -> None:
    """Load the sqlite-vec SQLite extension into the given database connection."""
    conn.load_extension(loadable_path())


from typing import List
from struct import pack
from sqlite3 import Connection


def serialize_float32(vector: List[float]) -> bytes:
    """Serializes a list of floats into the raw bytes format sqlite-vec expects"""
    return pack("%sf" % len(vector), *vector)


def serialize_int8(vector: List[int]) -> bytes:
    """Serializes a list of integers into the raw bytes format sqlite-vec expects"""
    return pack("%sb" % len(vector), *vector)


try:
    import numpy.typing as npt

    def register_numpy(db: Connection, name: str, array: npt.NDArray):
        ptr = array.__array_interface__["data"][0]
        nvectors, dimensions = array.__array_interface__["shape"]
        element_type = array.__array_interface__["typestr"]

        assert element_type == "<f4"

        name_escaped = db.execute("select printf('%w', ?)", [name]).fetchone()[0]

        db.execute(
            """
              insert into temp.vec_static_blobs(name, data)
              select ?, vec_static_blob_from_raw(?, ?, ?, ?)
            """,
            [name, ptr, element_type, dimensions, nvectors],
        )

        db.execute(
            f'create virtual table "{name_escaped}" using vec_static_blob_entries({name_escaped})'
        )

except ImportError:

    def register_numpy(db: Connection, name: str, array):
        raise Exception("numpy package is required for register_numpy")
