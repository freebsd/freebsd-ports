# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO_SWF
PORTVERSION=	2.2.3
CATEGORIES=	graphics www pear
MASTER_SITES=	http://openpear.org/get/ \
		LOCAL
MASTER_SITE_SUBDIR=	tota/${PKGNAMEPREFIX}${PORTNAME}
PKGNAMEPREFIX=	pear-

MAINTAINER=	yoya@awm.jp
COMMENT=	PEAR library for reading/writing SWF binary

LICENSE=	MIT

RUN_DEPENDS=	pear-IO_Bit>0:${PORTSDIR}/devel/pear-IO_Bit \
		${PEARDIR}/.channels/openpear.org.reg:${PORTSDIR}/devel/pear-channel-openpear

USE_PHP=	yes
PEAR_CHANNEL=	openpear
PEAR_AUTOINSTALL=	yes

x-generate-files: extract
	@${FIND} ${WRKSRC}/IO -type f | ${SORT} | ${SED} 's@${WRKSRC}/@@' |\
		${FMT} -50 | ${SED} -e 's@^@		@' -e 's@$$@ \\@'

x-generate-examples: extract
	@${FIND} ${WRKSRC}/sample -type f | ${SORT} | ${SED} 's@${WRKSRC}/sample/@@' |\
		${FMT} -50 | ${SED} -e 's@^@		@' -e 's@$$@ \\@'

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
