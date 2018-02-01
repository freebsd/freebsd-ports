# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lookup
PORTVERSION=	1.4.1
PORTREVISION=	19
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/edict/lookup/dist/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Emacs search interface for CD-ROM books, etc

LICENSE=	GPLv2

USES=		emacs

EMACS_FLAVORS_EXCLUDE=	devel_full and devel_nox # fail to build
INFO=		lookup lookup-guide
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/lookup

.include <bsd.port.mk>
