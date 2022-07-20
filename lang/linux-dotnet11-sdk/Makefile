PORTNAME=	dotnet10-sdk
DISTVERSION=	1.1.9
DISTNAME=	dotnet-dev-centos-x64.${DISTVERSION}
MASTER_SITES=	https://download.microsoft.com/download/4/0/2/4022CFC7-5061-4762-B9BA-48B35632572D/

RUN_DEPENDS=	linux-dotnet10-runtime>=0:lang/linux-dotnet10-runtime \
		linux-dotnet11-runtime>=0:lang/linux-dotnet11-runtime \
		bash:shells/bash

MASTERDIR=	${.CURDIR}/../linux-dotnet-sdk

EXTRACT_EXTRA_ARGS=

BINFILES=	sdk/${DISTVERSION}/corehost
SCRIPTFILES=	sdk/${DISTVERSION}/Roslyn/RunCsc.sh \
		sdk/${DISTVERSION}/Roslyn/RunVbc.sh \
		sdk/${DISTVERSION}/FSharp/RunFsc.sh

.include "${MASTERDIR}/Makefile"
