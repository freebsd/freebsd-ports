PORTNAME=	cvsutils
PORTVERSION=	0.2.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.red-bean.com/cvsutils/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS utilities which facilitate working with local working directories
WWW=		https://www.red-bean.com/cvsutils/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
SHEBANG_FILES=	cvs*.pl
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
