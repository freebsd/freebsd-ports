# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	4.16
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.maths.bath.ac.uk/pub/dream/newest/
DISTNAME=	Csound${PORTVERSION}
DIST_SUBDIR=	csound

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83

RESTRICTED=	"no redistribution; no commercial use except to make music (see http://mitpress.mit.edu/e-books/csound/fpage/FAQml/faq/faq.html#THE CSOUND COPYRIGHT ISSUES)"

MAKE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes

pre-build:
	find ${WRKDIR} -type f -exec ${CHMOD} 644 \{\} \;

post-build:
	${RM} -f ${PLIST}
	for i in `find ${WRKDIR} -type f -perm 755`; do \
		${ECHO} bin/`${BASENAME} $${i}` >> ${PLIST}; \
	done
	${ECHO} share/csound/csound.xmg >> ${PLIST}
	${ECHO} "@dirrm share/csound" >> ${PLIST}
	${ECHO} "*** WARNING ***" > ${PKGMESSAGE}
	${ECHO} "The sources for the csound package have not been" >> ${PKGMESSAGE}
	${ECHO} "thoroughly reviewed by the FreeBSD maintainer." >> ${PKGMESSAGE}

post-patch:
	${PERL} -pi -e "s:/usr/local/lib:${DATADIR}:g" ${WRKSRC}/getstring.c

do-install:
	${MKDIR} ${PREFIX}/share/csound
	${INSTALL_DATA} ${WRKSRC}/csound.xmg ${DATADIR}/csound.xmg
	${FIND} ${WRKDIR} -type f -perm 755 \
		-exec ${INSTALL_PROGRAM} {} ${PREFIX}/bin \;

.include <bsd.port.mk>
