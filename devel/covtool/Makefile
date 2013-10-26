# Created by: novator24 <novator24@gmail.com>
# $FreeBSD$

PORTNAME=	covtool
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/rel_2.0

MAINTAINER=	novator24@gmail.com
COMMENT=	C++ test coverage analyzer

WRKSRC=	        ${WRKDIR}
USE_ZIP=	yes
USE_GCC=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile

MAN1=		cov++.1 \
		covannotate.1 \
		covmerge.1 \
		covtool.1 \
		gen_html.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%PORTNAME%%|${PORTNAME}|g' ${WRKSRC}/cov++
	@${REINPLACE_CMD} 's|%%CXXFLAGS%%|${CXXFLAGS}|g' \
		${WRKSRC}/rules.FreeBSD

post-install:
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man/man1/,} \
		${MANPREFIX}/man/man1/
	@${INSTALL_DATA} ${WRKSRC}/cov++.cfg ${PREFIX}/etc/cov++.cfg.sample
	@if [ ! -f ${PREFIX}/etc/cov++.cfg ]; then \
		${CP} -p ${PREFIX}/etc/cov++.cfg.sample ${PREFIX}/etc/cov++.cfg ; \
	fi

.include <bsd.port.mk>
