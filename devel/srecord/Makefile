# ex:ts=8
# Ports collection makefile for:	srecord
# Date Created:			Aug 13, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	srecord
PORTVERSION=	1.50
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	abwang@gmail.com
COMMENT=	A collection of powerful tools for manipulating EPROM load files

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	gcrypt.17:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/srec_cat \
		bin/srec_cmp \
		bin/srec_info

MAN1=	srec_cat.1 \
	srec_cmp.1 \
	srec_examples.1 \
	srec_info.1 \
	srec_input.1 \
	srec_license.1
MAN5=	srec_aomf.5 \
	srec_ascii_hex.5 \
	srec_atmel_generic.5 \
	srec_binary.5 \
	srec_brecord.5 \
	srec_cosmac.5 \
	srec_dec_binary.5 \
	srec_emon52.5 \
	srec_fairchild.5 \
	srec_fastload.5 \
	srec_formatted_binary.5 \
	srec_fpc.5 \
	srec_intel.5 \
	srec_intel16.5 \
	srec_mos_tech.5 \
	srec_motorola.5 \
	srec_needham.5 \
	srec_os65v.5 \
	srec_signetics.5 \
	srec_spasm.5 \
	srec_spectrum.5 \
	srec_stewie.5 \
	srec_tektronix.5 \
	srec_tektronix_extended.5 \
	srec_ti_tagged.5 \
	srec_ti_tagged_16.5 \
	srec_ti_txt.5 \
	srec_vmem.5 \
	srec_wilson.5

do-install:
	@${INSTALL_PROGRAM} ${PLIST_FILES:S,^,${WRKSRC}/,} ${PREFIX}/bin/
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/man/man1/,} ${MAN1PREFIX}/man/man1/
	@${INSTALL_MAN} ${MAN5:S,^,${WRKSRC}/man/man5/,} ${MAN5PREFIX}/man/man5/

test:
	@cd ${WRKSRC} && ${MAKE} sure

.include <bsd.port.mk>
