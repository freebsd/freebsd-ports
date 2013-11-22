# Created by: Stas Timokhin <devel@stasyan.com>
# $FreeBSD$

CATEGORIES=	cad science

MASTERDIR=	${.CURDIR}/../salome

PORTNAME=	salome
PORTREVISION=	3
PKGNAMESUFFIX=	-kernel
SAL_MODULE_UPPER=	KERNEL

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-12-22

BROKEN=	Does not configure

NO_STAGE=	yes
post-configure::
	 @${INSTALL_SCRIPT} ${AUTOMAKE_DIR}/py-compile ${WRKSRC}/salome_adm/unix/config_files

.include "${MASTERDIR}/Makefile"
