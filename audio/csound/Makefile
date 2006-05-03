# New ports collection makefile for:	csound
# Date created:				2000-10-11
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	csound
PORTVERSION=	4.23
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_NETBSD}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Csound${PORTVERSION}
DIST_SUBDIR=	csound

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound synthesizer

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84

RESTRICTED=	"no redistribution; no commercial use except to make music (see http://mitpress.mit.edu/e-books/csound/fpage/FAQml/faq/faq.html)"
NO_CDROM=	${RESTRICTED}
NO_FTP=		${RESTRICTED}

MAKE_ENV=	CPPFLAGS="-I${PREFIX}/include" \
		LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib"
NO_WRKSUBDIR=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile on alpha"
.endif

pre-build:
	@${FIND} ${WRKDIR} -type f -exec ${CHMOD} 644 \{\} \;

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
	@${REINPLACE_CMD} -i "" -e "s:/usr/local/lib:${DATADIR}:g" ${WRKSRC}/getstring.c
	@${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -i -e 's:<malloc.h>:<stdlib.h>:g' {} \;

do-install:
	${MKDIR} ${PREFIX}/share/csound
	${INSTALL_DATA} ${WRKSRC}/csound.xmg ${DATADIR}/csound.xmg
	${FIND} ${WRKDIR} -type f -perm 755 \
		-exec ${INSTALL_PROGRAM} {} ${PREFIX}/bin \;

.include <bsd.port.post.mk>
