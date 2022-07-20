PORTNAME=	cvsdelta
PORTVERSION=	1.7.0
CATEGORIES=	devel
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/cvsdelta/ \
		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cvsdelta summarizes differences between local and in-cvs files

USE_RUBY=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/cvsdelta \
		man/man1/cvsdelta.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/cvsdelta.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
