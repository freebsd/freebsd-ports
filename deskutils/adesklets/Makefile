# New ports collection makefile for:	adesklets
# Date created:		2005-05-25
# Whom:			Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	adesklets
PORTVERSION=	0.6.1
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	An interactive Imlib2 console for the X Window system

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_XLIB=	yes

MAN1=		adesklets.1 \
		adesklets_checkin.1 \
		adesklets_installer.1 \
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

.if !defined(WITHOUT_PERL)
USE_PERL5=	yes
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=	--without-perl-support
PLIST_SUB+=	PERL="@comment "
.endif

.if defined(WITHOUT_HISTORY)
CONFIGURE_ARGS+=	--without-history
.endif

pre-everything::
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_PERL=yes to disable perl support"
	@${ECHO_MSG} "WITHOUT_HISTORY=yes to disable history support in interactive mode"
	@${ECHO_MSG} ""

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
