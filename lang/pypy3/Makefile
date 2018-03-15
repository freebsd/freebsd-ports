# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pypy3
DISTNAME=	${PORTNAME}-v${DISTVERSION}-src

MASTERDIR=	${.CURDIR}/../pypy

WRKSRC=		${WRKDIR}/${PORTNAME}-v${DISTVERSION:C/-.*//}-src
BUILD_WRKSRC?=	${WRKDIR}/build/usession-release-${PORTNAME}.5-v${DISTVERSION:C/-.*//}-0/testing_1

SHEBANG_FILES=	\
		lib-python/3/base64.py \
		lib-python/3/cProfile.py \
		lib-python/3/cgi.py \
		lib-python/3/encodings/rot_13.py \
		lib-python/3/keyword.py \
		lib-python/3/lib2to3/pgen2/token.py \
		lib-python/3/lib2to3/tests/data/different_encoding.py \
		lib-python/3/lib2to3/tests/data/false_encoding.py \
		lib-python/3/lib2to3/tests/pytree_idempotency.py \
		lib-python/3/pdb.py \
		lib-python/3/platform.py \
		lib-python/3/profile.py \
		lib-python/3/pydoc.py \
		lib-python/3/quopri.py \
		lib-python/3/smtpd.py \
		lib-python/3/smtplib.py \
		lib-python/3/symbol.py \
		lib-python/3/tabnanny.py \
		lib-python/3/tarfile.py \
		lib-python/3/test/crashers/recursive_call.py \
		lib-python/3/test/curses_tests.py \
		lib-python/3/test/pystone.py \
		lib-python/3/test/re_tests.py \
		lib-python/3/test/regrtest.py \
		lib-python/3/timeit.py \
		lib-python/3/trace.py \
		lib-python/3/turtledemo/bytedesign.py \
		lib-python/3/turtledemo/clock.py \
		lib-python/3/turtledemo/forest.py \
		lib-python/3/turtledemo/fractalcurves.py \
		lib-python/3/turtledemo/lindenmayer.py \
		lib-python/3/turtledemo/minimal_hanoi.py \
		lib-python/3/turtledemo/paint.py \
		lib-python/3/turtledemo/peace.py \
		lib-python/3/turtledemo/penrose.py \
		lib-python/3/turtledemo/planet_and_moon.py \
		lib-python/3/turtledemo/tree.py \
		lib-python/3/turtledemo/yinyang.py \
		lib-python/3/uu.py \
		lib-python/3/webbrowser.py \
		lib_pypy/_cffi_ssl/tools/make_ssl_data.py

PACKAGE_ARGS=	--without-_gdbm --without-sqlite3 --without-tk

PYPY_CFFI_VER=	${PORTNAME}-${DISTVERSION:C/.[^.]+$//:S/.//}-${ARCH}-${OPSYS:tl}${OSREL:C/\..*//}

pre-install:
	${FIND} ${WRKSRC} -name '*.pyc' -delete
	#${CHMOD} -R a-w ${WRKSRC}
	#${CHMOD} -R u+w ${WRKSRC}/lib_pypy

.include "${MASTERDIR}/Makefile"
