# New ports collection makefile for:	csound-manual
# Date created:				2000-10-11
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	csound-manual
PORTVERSION=	4.23
CATEGORIES=	audio
MASTER_SITES=	http://www.kevindumpscore.com/download/ \
		ftp://ftp.cs.bath.ac.uk/pub/dream/documentation/manuals/
DISTFILES=	manual-docbook-${PORTVERSION}.tar.gz \
		manual-html-${PORTVERSION}.tar.gz \
		manual-pdf-${PORTVERSION}.tar.gz \
		manual-text-${PORTVERSION}.tar.gz
DIST_SUBDIR=	csound

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Manuals for Csound

RUN_DEPENDS=	csound:${PORTSDIR}/audio/csound

NO_BUILD=		yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/pkg-plist
PREFIX=			${X11BASE}
WRKSRC=			${WRKDIR}/csound-${PORTVERSION}/manual

pre-install:
	@${RM} -f ${PLIST}
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's:^:share/doc/csound/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm share/doc/csound/:' >> ${PLIST}
		${ECHO_CMD} @dirrm share/doc/csound >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/share/doc/csound
	cd ${WRKSRC} && ${PAX} -r -w * ${PREFIX}/share/doc/csound

.include <bsd.port.mk>
