# $FreeBSD$

PORTNAME=	riece
PORTVERSION=	9.0.0
PORTEPOCH=	1
CATEGORIES=	irc elisp
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	IRC client for Emacs

USE_EMACS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
USE_GMAKE=	yes

INFO=	riece-en riece-ja

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS ChangeLog NEWS NEWS.ja README README.ja doc/HACKING doc/HACKING.ja
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
