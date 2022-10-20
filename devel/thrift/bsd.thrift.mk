# to use:
# in your makefile, set:
# PORTVERSION=	${THRIFT_PORTVERSION}
# see $PORTSDIR/devel/thrift for examples 
THRIFT_PORTVERSION=	0.16.0

MASTER_SITE_APACHE+=	https://archive.apache.org/dist/%SUBDIR%/ 
CONFIGURE_ARGS+=	\
		--without-tests

