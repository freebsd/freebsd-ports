# ex:ts=8
# Ports collection makefile for:	lafontaine
# Date created:			Sep 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lafontaine
PORTVERSION=	0.3R3
CATEGORIES=	lang
MASTER_SITES=	http://www.nongnu.org/lafontaine/archives/
DISTNAME=	${PORTNAME}-${PORTVERSION}-20020715

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical logo interpreter

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GNOME=	gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile on FreeBSD ${OSVERSION}"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|pixmaps/[\$$]PACKAGE|\$$PACKAGE|g ; \
		 s|-O3|\$$CFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|"\./pixmaps/|PIXMAPDIR "/|g' ${WRKSRC}/src/callbacks.c
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/share/pixmaps|/share|g'

.include <bsd.port.post.mk>
