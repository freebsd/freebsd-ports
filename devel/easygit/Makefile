# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	easygit
PORTVERSION=	0.98
CATEGORIES=	devel
MASTER_SITES=	http://www.gnome.org/~newren/eg/download/${PORTVERSION}/
DISTNAME=	eg
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy wrapper for git

RUN_DEPENDS=	git:devel/git

DISTREVISION=	0 # bump this if distfile is changed inplace

DIST_SUBDIR=	eg/${PORTVERSION}_${DISTREVISION}
USES=		perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/eg
USE_PERL5=	run
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/eg bin/easygit

do-extract:
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/eg ${STAGEDIR}${PREFIX}/bin/
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ./eg ${STAGEDIR}${PREFIX}/bin/easygit

.include <bsd.port.mk>
