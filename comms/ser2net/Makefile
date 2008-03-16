# New ports collection makefile for:	serialoverip
# Date created:		3 September 2006
# Whom:			Devon H. O'Dell <devon.odell@coyotepoint.com>
#
# $FreeBSD$
#

PORTNAME=	ser2net
PORTVERSION=	2.5
CATEGORIES=	comms net
MASTER_SITES=	SF

MAINTAINER=	devon.odell@coyotepoint.com
COMMENT=	Allows to access serial ports over IP

GNU_CONFIGURE=	yes
MAN8=		${PORTNAME}.8
USE_RC_SUBR=	${PORTNAME}

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README

post-patch:
	@${REINPLACE_CMD} -e's!/etc!${PREFIX}/etc!g' ${WRKSRC}/${PORTNAME}.c ${WRKSRC}/${PORTNAME}.8

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MAN8PREFIX}/man/man8/

.include <bsd.port.mk>
