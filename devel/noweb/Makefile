# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	noweb
PORTVERSION=	2.11b
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://www.eecs.harvard.edu/pub/nr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, extensible literate-programming tool

LICENSE=	noweb
LICENSE_NAME=	noweb
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	icont:lang/icon
RUN_DEPENDS=	iconx:lang/icon

# Master site uses extended passive mode fetch(1) does not support
FETCH_CMD=	/usr/bin/ftp
FETCH_ARGS=	# empty
DISABLE_SIZE=	yes

PORTSCOUT=	skipv:2.11

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
INSTALL_TARGET=	install-code install-man install-elisp
MAKE_ENV+=	INSTALL_PREFIX=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=	yes

NOWEBTEXDIR=	${STAGEDIR}${PREFIX}/share/texmf-local/tex/plain/noweb
NOWEBLATEXDIR=	${STAGEDIR}${PREFIX}/share/texmf-local/tex/latex/noweb

post-patch:
	@${TOUCH} ${WRKSRC}/c/modules.[ch]

post-build:
	@(cd ${WRKSRC} && ${SH} ${WRKSRC}/awkname awk)

post-install:
	@${MKDIR} ${NOWEBTEXDIR}
	${INSTALL_DATA} ${WRKSRC}/tex/nwmac.tex ${NOWEBTEXDIR}
	@${MKDIR} ${NOWEBLATEXDIR}
	${INSTALL_DATA} ${WRKSRC}/tex/noweb.sty ${NOWEBLATEXDIR}

.include <bsd.port.mk>
