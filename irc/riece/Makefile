# Created by: KIMURA Yasuhiro <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	riece
PORTVERSION=	9.0.0
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	irc elisp
MASTER_SITES=	SAVANNAH
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC client for Emacs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs gmake

NO_ARCH=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
INFO=		riece-en riece-ja

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS NEWS.ja README README.ja doc/HACKING doc/HACKING.ja
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
