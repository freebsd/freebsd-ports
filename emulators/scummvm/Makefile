# New ports collection makefile for:	scummvm
# Date created:				Tue Mar 26 13:05:21 CET 2002
# Whom:				Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	scummvm
PORTVERSION=	0.2.0
CATEGORIES=	games emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	adamw@FreeBSD.org

PORTCOMMENT=	Free implementation of LucasArts S.C.U.M.M. interpreter

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

USE_GMAKE=	yes
WRKSRC=         ${WRKDIR}/${PORTNAME}

#MAKEFILE=	Makefile.x11

pre-patch:
	@${FIND} -E ${WRKSRC} -type f -iregex ".*\.(cpp|h|txt)" \
		-exec ${PERL} -pi -ne 's!\r\n!\n!' {} 1>/dev/null 2>&1 \;
	@${PERL} -pi -e 's|\r\n|\n|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in copying.txt readme.txt whatsnew.txt
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
