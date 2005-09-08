# New ports collection makefile for:	adesklets
# Date created:		2005-05-25
# Whom:			Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	adesklets
PORTVERSION=	0.4.11
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An interactive Imlib2  console for the X Window system

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_BZIP2=	yes
USE_XLIB=	yes

MAN1=		adesklets.1 \
		adesklets_checkin.1 \
		adesklets_submit.1
INFO=		adesklets \
		adesklets_fr

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
