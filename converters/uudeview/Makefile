# New ports collection makefile for:	uulib
# Version Required:	0.5.4 (aka. 0.5pl4)
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id: Makefile,v 1.2 1996/08/23 09:04:06 asami Exp $
#

DISTNAME=	uudeview-0.5.4
CATEGORIES+=	archivers mail
MASTER_SITES=	http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/

MAINTAINER=	ac199@freenet.hamilton.on.ca

BUILD_DEPENDS=	${PREFIX}/lib/libuu.a:${PORTSDIR}/devel/uulib

GNU_CONFIGURE=	Yes
# Comment-out the next line and you'll probably enable posting.  I've
# never tried it, and if you do do it, pkg_delete won't delete all the 
# files that are installed.
# NOTE further that all you'll really do is cause uudeview to install
# its own minews do-hicky.
CONFIGURE_ARGS=		--disable-minews
CONFIGURE_ARGS+=	--disable-tcl

EXTRAFILES+=	porting.notes

# DOCDIR is used in bsd.own.mk
PORTDOCDIR?=	share/doc/uudeview
DOCFILES+=	porting.notes
DOCFILES+=	HOWTO

post-patch:
	@${ECHO_MSG} "===>  Adding extra files";
	@for l in ${EXTRAFILES}; do \
		cp ${FILESDIR}/$${l} ${WRKSRC}/$${l}; \
	done

# Maybe we should pay attention to DOCOWN, DOCGRP, and DOCMODE, set in 
# bsd.own.mk
post-install:
.if !defined(NOPORTDOCS)
	@if [ 'x${DOCFILES}' != x ] ; \
	then \
		${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"; \
	fi;
	mkdir -p ${PREFIX}/${PORTDOCDIR};
	@for l in ${DOCFILES}; \
	do \
		cp ${WRKSRC}/$$l ${PREFIX}/${PORTDOCDIR}; \
	done
.else
	@if [ 'x${DOCFILES}' != x ] ; \
	then \
		${ECHO_MSG} "===>  Not copying available documents to ${PREFIX}/${PORTDOCDIR}"; \
	fi;
.endif
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/uudeview.1
	gzip -9nf ${PREFIX}/man/man1/uuenview.1
.endif
	strip ${PREFIX}/bin/uudeview
	strip ${PREFIX}/bin/uuenview

.include <bsd.port.mk>
