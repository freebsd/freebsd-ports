# Created by: Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
# $FreeBSD$

PORTNAME=	pure
PORTVERSION=	0.6
PORTREVISION=	7
CATEGORIES=	irc elisp
#MASTER_SITES=	http://gouketsu.net/irchat-pj/src/2.5/
MASTER_SITES=	http://ftp.dti.ad.jp/pub/unix/net/irc/irchat-pj/2.5/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	pure-${PORTVERSION}p

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION}pl2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Primitive Universal Relay-chat Environment

LICENSE=	GPLv2 # (or later)

USE_BZIP2=	yes
USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21
LISPDIR?=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
EMACS_ONLY?=	""
XEMACS_ONLY?=	"@comment "
PUREBIN?=	bin
MAKE_ARGS+=	LISPDIR=${PREFIX}/${LISPDIR} \
		PACKDIR=${PREFIX}/${EMACS_LIBDIR}/site-packages \
		BINDIR=${PREFIX}/${PUREBIN}

PLIST_SUB=	PURELISP=${LISPDIR} \
		EMACS_ONLY=${EMACS_ONLY} \
		XEMACS_ONLY=${XEMACS_ONLY} \
		PUREBIN=${PUREBIN}

post-patch:
	@${REINPLACE_CMD} -e \
		's|CFLAGS=$$(CFLAGS)|| ; \
		 s|LDFLAGS=$$(LDFLAGS)||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|^\(CFLAGS\)=|\1?=| ; \
		 s|^\(LDFLAGS\)=|\1?=| ; \
		 s|^\(CC\)=|\1?=|' ${WRKSRC}/c/Makefile

post-install:
.for i in dccget dccput puresv
	@${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
