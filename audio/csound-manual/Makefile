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
PREFIX=			${X11BASE}/share/doc/csound
WRKSRC=			${WRKDIR}/csound-${PORTVERSION}

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKSRC} && ${FIND} -s . -type f | \
		${CUT} -c3-999 >> ${PLIST} \
		&& ${FIND} -d * -type d | ${SED} -e 's:^:@dirrm :' >> ${PLIST}

do-install:
	cd ${WRKSRC} && pax -r -w * ${PREFIX}

.include <bsd.port.mk>
