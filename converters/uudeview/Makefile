# New ports collection makefile for:	uulib
# Version Required:     0.5.9
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id: Makefile,v 1.5 1996/11/18 11:21:12 asami Exp $
#

DISTNAME=       uudeview-0.5.9
CATEGORIES=	archivers mail
MASTER_SITES=	http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	ac199@freenet.hamilton.on.ca

BUILD_DEPENDS=	${PREFIX}/lib/libuu.a:${PORTSDIR}/devel/uulib

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS+=        --enable-inews=${PREFIX}/news/lib/inews \
			--disable-tcl
MAN1=			uudeview.1 uuenview.1

EXTRAFILES+=	porting.notes

# DOCDIR is used in bsd.own.mk
PORTDOCDIR?=	share/doc/uudeview
DOCFILES+=	porting.notes
DOCFILES+=	HOWTO

post-patch:
	@${ECHO_MSG} "===>  Adding extra files";
	@for l in ${EXTRAFILES}; do \
		${CP} ${FILESDIR}/$${l} ${WRKSRC}/$${l}; \
	done

# Maybe we should pay attention to DOCOWN, DOCGRP, and DOCMODE, set in 
# bsd.own.mk
post-install:
.if !defined(NOPORTDOCS)
	@if [ 'x${DOCFILES}' != x ] ; \
	then \
		${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"; \
	fi;
	${MKDIR} ${PREFIX}/${PORTDOCDIR};
	@for l in ${DOCFILES}; \
	do \
		${CP} ${WRKSRC}/$$l ${PREFIX}/${PORTDOCDIR}; \
	done
.else
	@if [ 'x${DOCFILES}' != x ] ; \
	then \
		${ECHO_MSG} "===>  Not copying available documents to ${PREFIX}/${PORTDOCDIR}"; \
	fi;
.endif
	strip ${PREFIX}/bin/uudeview
	strip ${PREFIX}/bin/uuenview

.include <bsd.port.mk>
