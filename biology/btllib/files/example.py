import btllib
import sys

# Path to the sequencing reads file (can be plain text or compressed gzipped)
if len(sys.argv) != 2:
    print("Usage: python example.py <path_to_fastq_file>")
    sys.exit(1)
fastq_file = sys.argv[1]

# Configure reader flags (e.g., using long mode optimization for Oxford Nanopore or PacBio reads)
flags = btllib.SeqReaderFlag.LONG_MODE

# Initialize the sequence reader
reader = btllib.SeqReader(fastq_file, flags)

# Iterate through records efficiently
for record in reader:
    # Access metadata and genomic sequences
    record_id = record.id
    sequence = record.seq
    qualities = record.qual  # Only applicable for FASTQ formats
    
    print(f"ID: {record_id}")
    print(f"Length: {len(sequence)}")
    print(f"Sequence (first 20 bp): {sequence[:20]}")
    break  # Exit early for demonstration

