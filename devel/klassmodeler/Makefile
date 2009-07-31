# ex:ts=8
# Ports collection makefile for:	klassmodeler
# Date created:			Jun 29, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	klassmodeler
PORTVERSION=	0.8.2
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://www.jameswells.net/KlassModeler/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}.bsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for visually creating and documenting classes

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_GNOME=	gnometarget
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	WXWINDOWS="yes"
USE_WX=		2.4

PLIST_FILES=	bin/klassmodeler

DOS2FIX=	configure Makefile.in klassmodeler/docs/en/Makefile.in \
		klassmodeler/docs/Makefile.in klassmodeler/Makefile.in \
		admin/depcomp klassmodeler/MainFrame.cpp

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

post-patch:
.for df in ${DOS2FIX}
	${MV} ${WRKSRC}/${df} ${WRKSRC}/${df}.dos
	${TR} -d '\r' < ${WRKSRC}/${df}.dos > ${WRKSRC}/${df}
.endfor
	@${REINPLACE_CMD} -e "s,\`wx-config,\`${WX_CONFIG}," ${WRKSRC}/${CONFIGURE_SCRIPT}
	${CHMOD} a+x ${WRKSRC}/${CONFIGURE_SCRIPT}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/klassmodeler/klassmodeler ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/klassmodeler/docs/en/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
