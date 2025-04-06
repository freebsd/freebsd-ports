CONFIGURE_ARGS+=	--disable-gil

THREADFLAG=	t

MASTERDIR=	${.CURDIR}/../python313
CONFLICTS_INSTALL=	python313

.include "${MASTERDIR}/Makefile"

# blake2s_impl is regenerated
# regen requires at least 3.10, but JIT requires at least 3.11
.if ${PYTHON_DEFAULT:S/t$//} == 3.13 || ${PYTHON_DEFAULT:S/t$//} < 3.11
BUILD_DEPENDS+=	python3.12:lang/python312
.else
BUILD_DEPENDS+=	python${PYTHON_DEFAULT}:lang/python${PYTHON_DEFAULT:S/.//g}
.endif
