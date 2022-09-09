CATEGORIES=	japanese

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Pager/text-based WWW browser with Japanese support
WWW=		http://w3m.sourceforge.net/

MASTERDIR=	${.CURDIR}/../../www/w3m
PKGDIR=		${.CURDIR}
PLIST=		${MASTERDIR}/pkg-plist

OPTIONS_SLAVE=	DOCS JAPANESE
NO_DIALOG=	yes
CONFLICTS=	ja-w3m-img-0.5.* w3m-0.5.* w3m-img-0.5.*

.include "${MASTERDIR}/Makefile"
