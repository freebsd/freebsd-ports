# New ports collection makefile for:	libredblack
# Date created:		15 April 2002
# Whom:			smace@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libredblack
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library that provides the red-black balanced tree algorithm

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

MAN1=		rbgen.1
MAN3=		rbcloselist.3 rbdelete.3 rbdestroy.3 rbfind.3 rbinit.3 \
		rblookup.3 rbopenlist.3 rbreadlist.3 rbsearch.3 rbwalk.3

.if defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--without-rbgen
PLIST_SUB+=	PYTHON="@comment "
.else
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS =.*$$|CFLAGS = @CFLAGS@|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
