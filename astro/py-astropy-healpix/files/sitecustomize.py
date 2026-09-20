import numpy

if not hasattr(numpy, "in1d"):
    numpy.in1d = numpy.isin

try:
    from numpy.lib import _function_base_impl
except Exception:
    _function_base_impl = None

if _function_base_impl is not None and not hasattr(_function_base_impl, "_check_interpolation_as_method"):
    def _check_interpolation_as_method(method, interpolation, fname):
        if interpolation is None:
            return method
        if method != "linear" and interpolation != method:
            raise TypeError(
                f"Cannot pass both 'method' and deprecated 'interpolation' to {fname}()"
            )
        return interpolation

    _function_base_impl._check_interpolation_as_method = _check_interpolation_as_method
