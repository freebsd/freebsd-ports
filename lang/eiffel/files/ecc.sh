#!/bin/sh
PATH=$PATH:%%PREFIX%%/eiffel/bin
EIFFEL_S=%%PREFIX%%/eiffel

export EIFFEL_S PATH

exec %%PREFIX%%/eiffel/bin/ecc $*
