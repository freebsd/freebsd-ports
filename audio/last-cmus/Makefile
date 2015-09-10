# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	last
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://last-cmus.googlecode.com/files/ \
		http://mirror.mcx2.org/
PKGNAMESUFFIX=	-cmus
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}.py
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cmus plugin for submitting songs into last.fm

USES=		python
SUB_FILES=	pkg-message
NO_BUILD=	yes
PLIST_FILES=	bin/${DISTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}/last-cmus.py ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
