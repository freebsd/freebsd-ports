# New ports collection makefile for:	gforth
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gforth
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gforth

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Fast and portable Forth system

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
USE_GMAKE=	yes
ALL_TARGET=	all info
USE_GNOME=	gnometarget
USE_EMACS=	yes
EMACS_NO_BUILD_DEPENDS=	yes
EMACS_NO_RUN_DEPENDS=	yes

OPTIONS=	FFCALL	"Use ffcall"	on

CFLAGS+=	-fno-reorder-blocks -fno-inline
STRIP=		#none

PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		EMACS_DIR="${EMACS_SITE_LISPDIR}" \
		WORDSIZE=${WORDSIZE} BYTEORDER=${BYTEORDER}

DOC_FILES=	AUTHORS BUGS Benchres COPYING COPYING.DOC \
		INSTALL INSTALL.BINDIST NEWS README \
		NEWS.vmgen README.vmgen ToDo

MAN1=		gforth.1
INFO=		gforth vmgen
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FFCALL)
BUILD_DEPENDS=	${LOCALBASE}/include/avcall.h:${PORTSDIR}/devel/ffcall
.endif

.if ${OSVERSION} < 700000
BROKEN=		Does not compile on ports build cluster
.endif

.if ${OSVERSION} >= 700042 && ${ARCH} == "amd64"
BROKEN=		Does not compile
.endif

.if ${ARCH} == i386
WORDSIZE=32
.else
WORDSIZE=64
.endif

.if ${ARCH} == sparc64
BYTEORDER=b
.else
BYTEORDER=l
.endif

post-install: install-doc install-el remove-empty-files remove-empty-dirs

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for filename in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${filename} ${DOCSDIR}
.endfor
.endif

# Install Emacs syntax file
install-el:
	@${INSTALL_DATA} ${WRKSRC}/gforth.el ${PREFIX}/${EMACS_SITE_LISPDIR}

# Remove unused file
remove-empty-files:
	@${RM} -f ${DATADIR}/site-forth/siteinit.fs

# Remove unused directories
remove-empty-dirs:
	@${FIND} -d ${DATADIR}/${PORTVERSION}/arch/ -type d -empty -delete

.include <bsd.port.post.mk>
