# Stub version of "pyqt5" to avoid loading external dependencies.

def _impl(repository_ctx):
    return None

install_pyqt5 = repository_rule(
    attrs = {
        "python_interpreter": attr.string(default = "python"),
        "python_runtime": attr.string(mandatory=True),
    },
    local=True,
    implementation = _impl,
)
