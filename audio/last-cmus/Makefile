# New ports collection makefile for:	last-cmus
# Date created:				30 November 2008
# Whom:					Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	last
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://last-cmus.googlecode.com/files/ \
		http://mirror.mcx2.org/
PKGNAMESUFFIX=	-cmus
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}.py
EXTRACT_SUFX=	# none

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Cmus plugin for submitting songs into last.fm

USE_PYTHON=	yes
SUB_FILES=	pkg-message
NO_BUILD=	yes
PLIST_FILES=	bin/${DISTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}/last-cmus.py ${WRKSRC}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/
	@${CHMOD} +x ${PREFIX}/bin/${DISTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
