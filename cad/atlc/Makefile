# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atlc
PORTVERSION=	4.6.1
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to calculate the impedance of transmission lines

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

MAN1=		atlc.1 coax.1 create_bmp_for_circ_in_circ.1 \
		create_bmp_for_circ_in_rect.1 \
		create_bmp_for_microstrip_coupler.1 \
		create_bmp_for_rect_cen_in_rect.1 \
		create_bmp_for_rect_cen_in_rect_coupler.1 \
		create_bmp_for_rect_in_circ.1 \
		create_bmp_for_rect_in_rect.1 \
		create_bmp_for_stripline_coupler.1 \
		create_bmp_for_symmetrical_stripline.1 \
		design_coupler.1 dualcoax.1 \
		find_optimal_dimensions_for_microstrip_coupler.1 \
		readbin.1 sysdata.1
PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/atlc bin/coax bin/create_any_bitmap \
		bin/create_bmp_for_circ_in_circ \
		bin/create_bmp_for_circ_in_rect \
		bin/create_bmp_for_microstrip_coupler \
		bin/create_bmp_for_rect_cen_in_rect \
		bin/create_bmp_for_rect_cen_in_rect_coupler \
		bin/create_bmp_for_rect_in_circ \
		bin/create_bmp_for_rect_in_rect \
		bin/create_bmp_for_stripline_coupler \
		bin/create_bmp_for_symmetrical_stripline \
		bin/design_coupler bin/dualcoax \
		bin/find_optimal_dimensions_for_microstrip_coupler \
		bin/locatediff bin/myfilelength bin/mymd5sum bin/readbin

NO_STAGE=	yes
post-patch:
.for file in Makefile.in
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|docs examples||' ${WRKSRC}/${file}
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(${TAR} -C ${WRKSRC}/docs --exclude "*Makefile*" -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -)
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCDIR} | ${XARGS} ${CHOWN} ${SHHAREOWN}:${SHAREGRP}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(${TAR} -C ${WRKSRC}/examples --exclude "*Makefile*" -cf - . | \
		${TAR} -C ${EXAMPLESDIR} --unlink -xf -)
	@${FIND} ${DOCSDIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${FIND} ${DOCSDIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DOCDIR} | ${XARGS} ${CHOWN} ${SHHAREOWN}:${SHAREGRP}
.endif

.include <bsd.port.mk>
