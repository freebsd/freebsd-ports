# Created by: will
# $FreeBSD$

PORTNAME=	cvs2html
PORTVERSION=	1.98
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/${PORTVERSION}/ \
		http://cvs.sslug.dk/cvs2html/utils/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Perl script to turn ``cvs log'' output into HTML

LICENSE=	GPLv2

PLIST_FILES=	bin/cvs2html
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
# DragonFly has CVS in base and devel/cvs doesn't build there
RUN_DEPENDS=	cvs:devel/cvs
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${PORTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
