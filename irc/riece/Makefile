# Created by: KIMURA Yasuhiro <yasu@utahime.org>
# $FreeBSD$

PORTNAME=	riece
PORTVERSION=	9.0.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	irc elisp
MASTER_SITES=	SAVANNAH
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	IRC client for Emacs

LICENSE=	GPLv3

USES=		gmake
USE_EMACS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

OPTIONS_DEFINE=	DOCS

INFO=	riece-en riece-ja

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS NEWS.ja README README.ja doc/HACKING doc/HACKING.ja
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
