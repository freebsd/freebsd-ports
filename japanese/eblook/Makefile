# New ports collection makefile for:	eblook
# Date created:		20 August 1999
# Whom:			Shigeyuki Fukushima <shige@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	eblook
PORTVERSION=	1.3
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/lookup/DIST/eblook/

MAINTAINER=	shige@FreeBSD.org

DOCDIR=		share/doc/eblook

LIB_DEPENDS=    eb.3:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-eb-includes=${PREFIX}/include \
		--with-eb-libraries=${PREFIX}/lib

PLIST_SUB=	DOCDIR=${DOCDIR}

post-install:
.if !defined(NOPORTDOCS)
	@[ ! -d ${PREFIX}/${DOCDIR} ] && ${MKDIR} ${PREFIX}/${DOCDIR}
	@for i in AUTHORS COPYING ChangeLog NEWS README ; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR} ;\
	done
.endif

.include <bsd.port.mk>
