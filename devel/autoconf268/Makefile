# New ports collection makefile for:	autoconf
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	autoconf
PORTVERSION=	2.53
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	autoconf

MAINTAINER=	ports@geeksrus.net

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--without-lispdir

GENERIC_TOOLS=	config.guess	\
		config.sub	\
		elisp-comp	\
		install-sh	\
		mdate-sh	\
		missing		\
		mkinstalldirs

MAN1=		autoconf.1	\
		autoheader.1	\
		autom4te.1	\
		autoreconf.1	\
		autoscan.1	\
		autoupdate.1	\
		config.guess.1	\
		config.sub.1	\
		ifnames.1

post-install:
.for FILE in ${GENERIC_TOOLS}
	${INSTALL_SCRIPT} ${WRKSRC}/config/${FILE} ${PREFIX}/share/autoconf
.endfor

.include <bsd.port.mk>
