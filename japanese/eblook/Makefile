# Created by: Shigeyuki Fukushima <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eblook
PORTVERSION=	1.6.1
PORTREVISION=	7
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/
DIST_SUBDIR=	eb

MAINTAINER=	yasu@utahime.org
COMMENT=	Command to lookup words in EB format dictionaries

LICENSE=	GPLv2

LIB_DEPENDS=	eb:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-eb-includes=${PREFIX}/include \
			--with-eb-libraries=${PREFIX}/lib

INFO=		eblook

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	for i in AUTHORS COPYING ChangeLog NEWS README ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${DOCSDIR} ;\
	done
.endif

.include <bsd.port.mk>
