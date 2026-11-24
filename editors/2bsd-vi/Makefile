PORTNAME=	vi
DISTVERSION=	4.1.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	editors
PKGNAMEPREFIX=	2bsd-

MAINTAINER=	mce@FreeBSD.org
COMMENT=	The original vi editor, updated to run on modern OSes
WWW=		https://github.com/n-t-roff/heirloom-ex-vi/

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	n-t-roff
GH_PROJECT=	heirloom-ex-vi
GH_TAGNAME=	3f1e9786d249d18012600ae21175eb3521579402

HAS_CONFIGURE=	yes

PRESERVEDIR=	/var/preserve/${PKGBASE}
PLIST_SUB=	PRESERVEDIR="${PRESERVEDIR}"

post-extract:
	@${RM} -r ${WRKSRC}/libuxre ${WRKSRC}/regexp.h

post-patch:
	${REINPLACE_CMD} -e '/^PREFIX/s,/usr/local,${PREFIX},' \
		${WRKSRC}/Makefile.in
.for f in Makefile.in ex.1 expreserve.c exrecover.c vi.1
	${REINPLACE_CMD} -e 's,/var/preserve,${PRESERVEDIR},' ${WRKSRC}/${f}
.endfor

.include <bsd.port.mk>
