# New ports collection makefile for:	opmixer
# Date created:				2000-12-29
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	opmixer
PORTVERSION=	0.70
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	optronic

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Adjusts a mixer

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

DOCDIR=		share/doc/${PORTNAME}
USE_BZIP2=	yes
USE_X_PREFIX=	yes
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/opmixer

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile on FreeBSD >= 5.x"
.endif

pre-install:
	${ECHO_CMD} "bin/opmixer" > ${PLIST}
	${ECHO_CMD} "bin/opmixer-load" >> ${PLIST}
	${ECHO_CMD} "bin/volset" >> ${PLIST}
.if !defined(NOPORTDOCS)
	${ECHO_CMD} ${DOCDIR}/README >> ${PLIST}
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opmixer ${WRKSRC}/opmixer-load \
		${WRKSRC}/volset ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
