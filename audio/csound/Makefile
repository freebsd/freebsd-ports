# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	4.20
CATEGORIES=	audio
MASTER_SITES=	ftp://sunsite.univie.ac.at/pub/sound/csound/newest/ \
		ftp://ftp.cs.bath.ac.uk/pub/dream/newest/
DISTNAME=	Csound${PORTVERSION}
DIST_SUBDIR=	csound

MAINTAINER=	trevor@FreeBSD.org

BROKEN=		"Does not fetch"

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83

RESTRICTED=	"no redistribution; no commercial use except to make music (see http://mitpress.mit.edu/e-books/csound/fpage/FAQml/faq/faq.html)"
NO_CDROM=	${RESTRICTED}
NO_FTP=		${RESTRICTED}

MAKE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes

pre-build:
	${FIND} ${WRKDIR} -type f -exec ${CHMOD} 644 \{\} \;

post-build:
	${RM} -f ${PLIST}
	for i in `${FIND} ${WRKDIR} -type f -perm 755`; do \
		${ECHO_CMD} bin/`${BASENAME} $${i}` >> ${PLIST}; \
	done
	${ECHO_CMD} share/csound/csound.xmg >> ${PLIST}
	${ECHO_CMD} "@dirrm share/csound" >> ${PLIST}
	${ECHO_CMD} "*** WARNING ***" > ${PKGMESSAGE}
	${ECHO_CMD} "The sources for the csound package have not been" >> ${PKGMESSAGE}
	${ECHO_CMD} "thoroughly reviewed by the FreeBSD maintainer." >> ${PKGMESSAGE}

post-patch:
	${PERL} -pi -e "s:/usr/local/lib:${DATADIR}:g" ${WRKSRC}/getstring.c
	${FIND} ${WRKSRC} -type f -exec \
		${PERL} -pi -e "s:<malloc.h>:<stdlib.h>:g" {} \;

do-install:
	${MKDIR} ${PREFIX}/share/csound
	${INSTALL_DATA} ${WRKSRC}/csound.xmg ${DATADIR}/csound.xmg
	${FIND} ${WRKDIR} -type f -perm 755 \
		-exec ${INSTALL_PROGRAM} {} ${PREFIX}/bin \;

.include <bsd.port.mk>
