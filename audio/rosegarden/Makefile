# New ports collection makefile for:	rosegarden
# Date created:		04 Aug 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	rosegarden
PORTVERSION=	2.1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.cannam.demon.co.uk/rosegarden/distribution/
DISTNAME=	${PORTNAME}-2.1pl2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Rosegarden Editor and Sequencer suite

BUILD_DEPENDS=	${LOCALBASE}/lib/tclmidi/tclmidi31.so:${PORTSDIR}/audio/tclmidi
RUN_DEPENDS=	${LOCALBASE}/lib/tclmidi/tclmidi31.so:${PORTSDIR}/audio/tclmidi

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	213
CONFIGURE_ARGS=	--with-tclincl=${LOCALBASE}/include/tcl8.2

post-patch:
	@${CP} ${FILESDIR}/rosegarden ${WRKSRC}/rosegarden.sh
.for file in Rosegarden rosegarden.sh
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

do-install:
	@( \
	 cd ${WRKSRC} ; ${SETENV} PREFIX="${PREFIX}" ./do-install \
	)
	${INSTALL_SCRIPT} ${WRKSRC}/rosegarden.sh ${PREFIX}/bin/rosegarden

.include <bsd.port.mk>
