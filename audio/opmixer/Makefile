# New ports collection makefile for:	opmixer
# Date created:				2000-12-29
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	opmixer
PORTVERSION=	0.5
CATEGORIES=	audio
MASTER_SITES=	http://optronic.linuxave.net/wizborn/projects/opmixer/

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	gtkmm.1:${PORTSDIR}/x11-toolkits/gtk-- \
		intl.1:${PORTSDIR}/devel/gettext

DOCDIR=		share/doc/${PORTNAME}
USE_BZIP2=	yes
USE_X_PREFIX=	yes
PLIST=		${WRKDIR}/pkg-plist
WRKSRC=		${WRKDIR}/opmixer

pre-install:
	${ECHO} "bin/opmixer" > ${PLIST}
	${ECHO} "bin/opmixer-load" >> ${PLIST}
.if !defined(NOPORTDOCS)
	${ECHO} ${DOCDIR}/README >> ${PLIST}
	${ECHO} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opmixer ${WRKSRC}/opmixer-load \
		${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
.endif

.include <bsd.port.mk>
