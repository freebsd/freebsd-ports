# New ports collection makefile for:	opmixer
# Date created:				2000-12-29
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	opmixer
PORTVERSION=	0.60
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	optronic

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
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

do-patch:
.if exists(/usr/include/machine/soundcard.h)
	${PERL} -pi -e "s=sys/soundca=machine/soundca=g" ${WRKSRC}/ossmixer.hh
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opmixer ${WRKSRC}/opmixer-load \
		${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/${DOCDIR}
.endif

.include <bsd.port.mk>
