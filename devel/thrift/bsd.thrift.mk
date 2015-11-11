#
# $FreeBSD$
#
# to use:
# in your makefile, set:
# PORTVERSION=	${THRIFT_PORTVERSION}
# see $PORTSDIR/devel/thrift for examples 
THRIFT_PORTVERSION=	0.9.3
THRIFT_PORTREVISION=	1

CONFIGURE_ARGS+=	\
		--without-tests

