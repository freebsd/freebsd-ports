CONFIGURE_ARGS+=	--disable-gil

THREADFLAG=	t
LDFLAGS+=	-lkvm

MASTERDIR=	${.CURDIR}/../python314
CONFLICTS_INSTALL=	python314

# https://github.com/python/cpython/issues/133171
OPTIONS_EXCLUDE+=	JIT

.include "${MASTERDIR}/Makefile"
