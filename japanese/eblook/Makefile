# New ports collection makefile for:	eblook
# Date created:		20 August 1999
# Whom:			Shigeyuki Fukushima <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eblook
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/
DIST_SUBDIR=	eb

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive EB interface command for seraching words in electoric dictionaries

LIB_DEPENDS=	eb.10:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-eb-includes=${PREFIX}/include \
			--with-eb-libraries=${PREFIX}/lib

INFO=		eblook

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for i in AUTHORS COPYING ChangeLog NEWS README ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${DOCSDIR} ;\
	done
.endif

.include <bsd.port.mk>
