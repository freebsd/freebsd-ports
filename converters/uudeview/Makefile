# New ports collection makefile for:	uudeview
# Version Required:     0.5.9
# Date Created:		04 Aug 1996
# Whom:			Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
#
# $Id: Makefile,v 1.11 1997/04/27 00:23:50 asami Exp $
#

DISTNAME=       uudeview-0.5.13
CATEGORIES=	converters
MASTER_SITES=	http://www.uni-frankfurt.de/~fp/uudeview/Apps/frank/  \
		ftp://ftp.uni-frankfurt.de/pub/dist/frank/  \
		ftp://tsx-11.mit.edu/pub/linux/sources/usr.bin/

MAINTAINER=	hoek@FreeBSD.ORG

LIB_DEPENDS=	uu\\.1\\.:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS+=        --enable-inews=${PREFIX}/news/lib/inews \
			--disable-tcl
MAN1=		uudeview.1 uuenview.1

PORTDOCDIR?=	share/doc/uudeview

post-install:
	@/usr/bin/strip ${PREFIX}/bin/uudeview
	@/usr/bin/strip ${PREFIX}/bin/uuenview
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	@${INSTALL_MAN} ${WRKSRC}/HOWTO ${PREFIX}/${PORTDOCDIR}
	@${INSTALL_MAN} ${FILESDIR}/porting.notes ${PREFIX}/${PORTDOCDIR}
.else
	@${ECHO_MSG} "===>  Not copying available documents"
.endif

.include <bsd.port.mk>
