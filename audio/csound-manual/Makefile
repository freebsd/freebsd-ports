# New ports collection makefile for:	csound-manual
# Date created:				2000-10-11
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	csound-manual
PORTVERSION=	4.10
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.csounds.com/manual/current/
DISTFILES=	ascii.zip \
		espanol.zip \
		html.zip \
		manual1.zip \
		manual2.zip \
		spplmnt1.zip \
		spplmnt2.zip \
		spplmtxt.zip \
		toots.zip
DIST_SUBDIR=	csound

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	csound:${PORTSDIR}/audio/csound

RESTRICTED=	"no redistribution; no commercial use except to make music (see http://mitpress.mit.edu/e-books/csound/fpage/FAQml/faq/faq.html#THE CSOUND COPYRIGHT ISSUES)"

NO_BUILD=		yes
NO_MTREE=		yes
PLIST=			${WRKDIR}/pkg-plist
PREFIX=			${X11BASE}/share/doc/csound
USE_ZIP=		yes
WRKSRC=			${WRKDIR}/manual
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

pre-extract:
	${MKDIR} ${WRKSRC}

pre-install:
	${RM} -f ${PLIST}
	cd ${WRKDIR}/manual && find -s . -type f | cut -c3-999 >> ${PLIST} \
	&& find * -type d | ${SED} -e 's:^:@dirrm :' >> ${PLIST}

do-install:
	cd ${WRKSRC} && pax -r -w * ${PREFIX}

.include <bsd.port.mk>
