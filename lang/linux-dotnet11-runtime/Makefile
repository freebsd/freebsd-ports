PORTNAME?=	dotnet11-runtime
DISTNAME=	dotnet-centos-x64.${DISTVERSION}
DISTVERSION?=	1.1.8
MASTER_SITES?=	https://download.microsoft.com/download/1/B/8/1B80E25B-316E-4DFB-9707-DB758681F175/

MASTERDIR=	${.CURDIR}/../linux-dotnet-runtime

BINFILES=	shared/Microsoft.NETCore.App/${DISTVERSION}/corehost shared/Microsoft.NETCore.App/${DISTVERSION}/dotnet

.include "${MASTERDIR}/Makefile"
