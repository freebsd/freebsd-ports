# New ports collection makefile for:	darcs
# Date created:				13 April 2003
# Whom:					Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	darcs
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://darcs.net/

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Yet another replacement for CVS, written in Haskell

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc
LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		gmp.8:${PORTSDIR}/math/libgmp4

OPTIONS=	SERVER "install server" on
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${PREFIX}/lib/ ${PTHREAD_LIBS}" \
		CFLAGS=""
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
INSTALL_TARGET=	install
PORTDOCS=	manual examples

.include <bsd.port.pre.mk>

.if defined(WITH_SERVER)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
RUN_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt
INSTALL_TARGET+=	installserver
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
.else
CGIDIR?=	www/cgi-bin
.endif
PLIST_SUB+=	CGIDIR=${CGIDIR} SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base \
		latex2html:${PORTSDIR}/textproc/latex2html
ALL_TARGET+=	doc/manual/darcs.ps doc/manual/patch-theory.pdf doc/manual/index.html
INSTALL_TARGET+=	install-ps install-pdf install-html install-examples
.else
CONFIGURE_ARGS+=	--without-manual
.endif

MAN1=	darcs.1

.if defined(WITH_SERVER)
post-patch:
	@${REINPLACE_CMD} -e 's|$$(libexecdir)/cgi-bin|${PREFIX}/${CGIDIR}| ; \
		s|darcs/cgi.conf|darcs/cgi.conf.sample|' \
		${WRKSRC}/${MAKEFILE}
.endif

pre-configure:
.if ${OSVERSION} < 700000
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"###############################################################################"
	@${ECHO_MSG}	"                                                                               "
	@${ECHO_MSG}	"                                A T T E N T I O N                              "
	@${ECHO_MSG}	"                                                                               "
	@${ECHO_MSG}	"If you experience problems during the configure process, please add the        "
	@${ECHO_MSG}    "following lines to your /etc/libmap.conf configuration file:                   "
	@${ECHO_MSG}    "                                                                               "
	@${ECHO_MSG}    "libpthread.so.1 libthr.so.1                                                    "
	@${ECHO_MSG}    "libpthread.so.2 libthr.so.2                                                    "
	@${ECHO_MSG}    "libkse.so.3 libthr.so.3                                                        "
	@${ECHO_MSG}    "                                                                               "
	@${ECHO_MSG}	"###############################################################################"
	@${ECHO_MSG}	""
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/darcs

.include <bsd.port.post.mk>
