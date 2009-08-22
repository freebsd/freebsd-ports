# New ports collection makefile for:	sybtcl
# Date created:			Jul 30, 2002
# Whom:				mi
#
# $FreeBSD$
#

PORTNAME=	sybtcl
PORTVERSION=	3.0rc2
PORTREVISION=	2
CATEGORIES=	databases devel
MASTER_SITES=	SF

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	TCL extension to connect to Sybase servers

LIB_DEPENDS=	sybdb:${PORTSDIR}/databases/freetds

USE_TCL=	83+
TCL_DVER=	${TCL_VER:S/.//}
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	TCL_VER=${TCL_VER}

MANN=		${PORTNAME}.n

post-install:
	#######
	# This port installs two of the vendor-supplied sample programs,
	# which have general-purpose utility. If you'd like to browse
	# through other examples, do ``make patch'' and look inside the
	# ${WRKSRC}/samples
	#######

.include <bsd.port.mk>
