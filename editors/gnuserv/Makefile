# New ports collection makefile for:   gnuserv
# Date created:        10 February 2001
# Whom:                ilya
#
# $FreeBSD$
#

PORTNAME=	gnuserv
PORTVERSION=	3.12.8
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://meltin.net/hacks/emacs/src/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	A standalone release of gnuserv for GNU Emacs

MAKE_JOBS_SAFE=  yes

GNU_CONFIGURE=	yes

BINSUFFIX?=	-emacs

USE_EMACS=	yes

.if defined(WITHOUT_X11)
BROKEN=		Configure fails without X support
.endif

CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include --x-libraries=${PREFIX}/lib

# configure --program-suffix doesn't work somehow
MAKE_ARGS=	binsuffix="${BINSUFFIX}"

PORTDOCDIR=	share/doc/gnuserv-${EMACS_PORT_NAME}
MAN1=		gnuserv${BINSUFFIX}.1
MLINKS=		gnuserv${BINSUFFIX}.1 gnuattach${BINSUFFIX}.1 \
		gnuserv${BINSUFFIX}.1 gnuclient${BINSUFFIX}.1 \
		gnuserv${BINSUFFIX}.1 gnudoit${BINSUFFIX}.1
DOCS=		COPYING ChangeLog INSTALL README README.orig
SOURCES=	devices.el gnuserv-compat.el gnuserv.el
ELCS=		${SOURCES:S/.el/.elc/g}

PLIST_SUB=	EMACS_PORT_NAME=${EMACS_PORT_NAME} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR} \
		BINSUFFIX=${BINSUFFIX}

lispdir=	${PREFIX}/${EMACS_SITE_LISPDIR}/gnuserv

post-patch:
.for i in gnudoit gnuattach
	@${REINPLACE_CMD} 's/gnuclient/gnuclient${BINSUFFIX}/' ${WRKSRC}/${i}
.endfor

post-install:
	${MKDIR} ${lispdir};
.for i in ${SOURCES} ${ELCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${lispdir}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${PORTDOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
