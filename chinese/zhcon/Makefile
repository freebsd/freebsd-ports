# Ports collection makefile for:  zhcon
# Date created:                   Sun Sep 9, 2001
# Whom:                           statue@freebsd.sinica.edu.tw
#
# $FreeBSD$
#

PORTNAME=	zhcon
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	statue@freebsd.sinica.edu.tw

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-included-gettext=${LOCALBASE}
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAN1=		zhcon.1

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} > 500012
	@${FIND} ${WRKSRC}/src/ -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -e 's,machine/console.h>,sys/consio.h>\n#include <sys/fbio.h>\n#include <sys/kbio.h>\n,'
.endif

.include <bsd.port.post.mk>
